n , cities = 0, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]






def solution(cacheSize, cities):

    lists = list()
    ans = 0
    for city in cities :
        city = city.upper()
        if cacheSize != 0 :
            if city not in lists :
                if cacheSize == len(lists) :
                    lists.pop(0)
                ans += 5
                lists.append(city)
            else :
                lists.pop(lists.index(city))
                ans += 1
                lists.append(city)
        else :
            ans += 5
    return ans

print(solution(n,cities))