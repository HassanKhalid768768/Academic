from mrjob.job import MRJob
from datetime import datetime

class TimeSpentInClass(MRJob):

    def mapper(self, _, line):
        data = line.split()
        rollnumber = data[0]
        course_semester = (data[1].split(':')[1], data[2].split(':')[1])
        login_time = datetime.strptime(data[3] + ' ' + data[4], '%m-%d-%y %H:%M')
        logout_time = datetime.strptime(data[5] + ' ' + data[6], '%m-%d-%y %H:%M')
        time_spent_in_class = (logout_time - login_time).total_seconds() / 60
        total_time_spent = (datetime.strptime('12-31-20 23:59', '%m-%d-%y %H:%M') - login_time).total_seconds() / 60
        yield (rollnumber, course_semester), (time_spent_in_class, total_time_spent)

    def reducer(self, key, values):
        time_spent_in_class_total = sum(value[0] for value in values)
        total_time_spent_total = sum(value[1] for value in values)
        yield key[0], (key[1], time_spent_in_class_total / total_time_spent_total * 100)

    def combiner(self, key, values):
        yield key, list(values)

    def reducer_final(self, key, values):
        yield key, [item for sublist in values for item in sublist]

if __name__ == '__main__':
    TimeSpentInClass.run()
