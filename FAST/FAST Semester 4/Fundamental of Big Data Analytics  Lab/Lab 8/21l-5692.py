# Question 1

from mrjob.job import MRJob

class SongCounter(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        username = parts[0].strip()
        date = parts[1].strip()
        num_songs = len(parts) - 2
        if num_songs > 5:
            yield username, None

if __name__ == '__main__':
    SongCounter.run()
    

# Question 2

from mrjob.job import MRJob

class SongCounter(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        username = parts[0].strip()
        date = parts[1].strip()
        num_songs = len(parts) - 2
        yield username, (date, num_songs)

if __name__ == '__main__':
    SongCounter.run()

    
# Question 3

from mrjob.job import MRJob

class SongCounter(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        username = parts[0].strip()
        date = parts[1].strip()
        num_songs = len(parts) - 2
        yield username, num_songs

    def combiner(self, username, num_songs_iter):
        yield username, sum(num_songs_iter)

    def reducer(self, username, num_songs_iter):
        yield username, sum(num_songs_iter)

if __name__ == '__main__':
    SongCounter.run()

    
# Question 4

from mrjob.job import MRJob

class SongAverage(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        num_songs = len(parts) - 2
        yield 'total_songs', num_songs
        yield 'total_days', 1

    def combiner(self, key, value_iter):
        if key == 'total_songs':
            yield key, sum(value_iter)
        else:
            yield key, sum(value_iter)

    def reducer(self, key, value_iter):
        if key == 'total_songs':
            total_songs = sum(value_iter)
            yield 'avg_songs', float(total_songs) / self.days
        else:
            total_days = sum(value_iter)
            self.days = total_days

if __name__ == '__main__':
    SongAverage.run()


# Question 5

from mrjob.job import MRJob

class SongCount(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        for song in parts[2:]:
            yield song.strip(), 1

    def combiner(self, song, count_iter):
        yield song, sum(count_iter)

    def reducer(self, song, count_iter):
        yield song, sum(count_iter)

if __name__ == '__main__':
    SongCount.run()

    
# Question 6

from mrjob.job import MRJob

class MaxSongsInDay(MRJob):

    def mapper(self, _, line):
        parts = line.split(',')
        username, date, songs = parts[0], parts[1], parts[2:]
        yield (username, date), len(songs)

    def combiner(self, user_date, count_iter):
        yield user_date, sum(count_iter)

    def reducer(self, user_date, count_iter):
        yield None, (user_date[0], user_date[1], sum(count_iter))

    def reducer_max(self, _, user_count_iter):
        max_user = None
        max_count = -1
        for user_count in user_count_iter:
            if user_count[2] > max_count:
                max_count = user_count[2]
                max_user = user_count[0]
        yield max_user, max_count

if __name__ == '__main__':
    MaxSongsInDay.run()

    
# Question 7

from mrjob.job import MRJob

class UserSongCount(MRJob):

    def mapper(self, _, line):
        user, date, songs = line.strip().split(',')
        for song in songs.split():
            yield user, 1

    def combiner(self, user, counts):
        yield user, sum(counts)

    def reducer(self, user, counts):
        total_count = sum(counts)
        max_count = max(self.counts())
        if total_count == max_count:
            yield user, total_count

if __name__ == '__main__':
    UserSongCount.run()

    
# Question 8

from mrjob.job import MRJob

class UserDateSongCount(MRJob):

    def mapper(self, _, line):
        user, date, songs = line.strip().split(',')
        for song in songs.split():
            yield (user, date), 1

    def combiner(self, user_date, counts):
        yield user_date, sum(counts)

    def reducer(self, user_date, counts):
        total_count = sum(counts)
        max_count = max(self.counts())
        if total_count == max_count:
            yield user_date[0], user_date[1]

if __name__ == '__main__':
    UserDateSongCount.run()




    
 