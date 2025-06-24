from mrjob.job import MRJob

class MaxTempOfYear(MRJob):

    def mapper(self, _, line):
        fields = line.split(",")
        date = fields[0]
        year = date.split("-")[2]
        temperature = int(fields[1])
        yield year, temperature

    def reducer(self, year, temperatures):
        max_temp = max(temperatures)
        yield year, max_temp
