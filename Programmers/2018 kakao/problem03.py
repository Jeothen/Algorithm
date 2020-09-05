
n,t,m,timetable = 2, 10, 3, ["09:00","09:00","09:00","09:00","09:10", "09:09", "08:00"]



bus = []
people = []

def solution(n,t,m,timetable):
    bus_start = 540
    for i in range(n):
        bus.append(bus_start)
        bus_start += t
    for i in range(len(timetable)):
        hour, minute = map(int,timetable[i].split(':'))
        people.append(hour*60+minute)
    people.sort()
    tmp = 0
    print(bus)
    print(people)
    bus_index = 0
    people_index = 0
    people_cnt = 0

    while bus_index < n :
        people_cnt = 0
        while bus[bus_index] >= people[people_index] and people_cnt < m:
            people_cnt += 1
            if people[people_index] <= bus[bus_index] :
                if m == people_cnt : # 사람이 다 찼을때
                    tmp = people[people_index]-1

                if bus[bus_index] < people[people_index] and people_cnt < m : # 사람이 다 안찼을때
                    tmp = people[people_index]
            people_index += 1
            if people_index == len(people) : break
        if people_cnt < m :
            tmp = bus[bus_index]

        bus_index += 1

    hour = str(tmp // 60)
    minute = str((tmp - (int(hour) * 60))% 60)
    if len(minute) == 1 :
        minute = '0' + minute
    if len(hour) == 1 :
        hour = '0' + hour
    ans = str(hour) + ":" + minute
    return ans

print(solution(n,t,m,timetable))