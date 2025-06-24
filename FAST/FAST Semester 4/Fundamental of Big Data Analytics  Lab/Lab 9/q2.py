from mrjob.job import MRJob

class DistinctStudents(MRJob):
    
    def mapper(self, _, line):
        fields = line.split(' ')
        course = fields[1].split(':')[1]
        rollno = fields[0]
        yield course, rollno
        
    def reducer(self, course, rollnos):
        students = set(rollnos)
        yield course, len(students)
        
if __name__ == '__main__':
    DistinctStudents.run()
