
lines = ["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"]


import datetime
import queue

def solution(lines):
    t = []
    q = queue.Queue()
    length = len(lines)
    for line in lines :
        year, month, tmp = line.split('-')
        day,times, laps = tmp.split(' ')
        hour, minute, tmp2 = times.split(':')
        second, remnant = tmp2.split('.')
        year, month, day, hour, minute, second = map(int, (year,month,day,hour,minute,second))
        remnant = int(remnant)*1000
        end = datetime.datetime(year,month,day,hour,minute,second, remnant)
        laps = laps[:-1]

        if '.' in laps :
            lap_second, lap_remnant = laps.split('.')
        else :
            lap_second = int(laps)
            lap_remnant = '0'
        if len(lap_remnant) == 1 :
            lap_remnant += '00'
        elif len(lap_remnant) == 2 :
            lap_remnant += '0'

        lap_second = int(lap_second)
        lap_remnant = int(lap_remnant) * 1000
        lap_remnant -= 1000
        start = datetime.datetime(year, month, day, hour, minute, second, remnant) - datetime.timedelta(0,lap_second,lap_remnant)
        print(start, end)
        q.put(start)
        q.put(end)
        t.append([start,end])

    maximum = 0

    while q.qsize() :
        cnt = 0
        s = q.get()
        e = s + datetime.timedelta(0,0,999000)
        for i in range(length) :
            if s <= t[i][0] <= e or s <= t[i][1] <= e :
                cnt += 1
            elif t[i][0] <= s and e <= t[i][1] :
                cnt += 1
        if maximum < cnt :
            maximum = cnt
    return maximum

print(solution(lines))