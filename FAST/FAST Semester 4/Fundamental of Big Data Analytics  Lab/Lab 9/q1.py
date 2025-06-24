from mrjob.job import MRJob

class StudentCourseAccess(MRJob):
    
    def mapper(self, _, line):
        # parse the input line and extract necessary fields
        roll_no, _, _, login_time, _, _, _, accessed_pages = line.split()
        year = login_time.split('-')[2]
        course = accessed_pages.split(':')[1].strip()
        
        # emit the key-value pair
        yield (year, roll_no, course), 1
    
    def combiner(self, key, values):
        # sum the number of accesses by the same student to the same course in the same year
        yield key, sum(values)
        
    def reducer(self, key, values):
        # sum the number of accesses by the same student to the same course in the same year
        yield key, sum(values)
        
if __name__ == '__main__':
    StudentCourseAccess.run()
