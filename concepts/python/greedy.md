# Greedy

From wikipedia

> A greedy algorithm is any algorithm that follows the problem-solving heuristic of making the locally optimal choice at each stage. In many problems, a greedy strategy does not produce an optimal solution, but a greedy heuristic can yield locally optimal solutions that approximate a globally optimal solution in a reasonable amount of time.

## 💻 Implementation

### Problems: Set-covering problem

Problem: Suppose you’re starting a radio show. You want to reach listeners in X number of cities. You have to decide what stations to play on to reach all those listeners. It costs money to be on each station, so you’re trying to minimize the number of stations you play on. You have a list of stations. Each station covers a region, and there’s overlap. How do you figure out the smallest set of stations you can play on to cover all the cities?

Brute Force Approach: List every possible subset of stations. From these, pick the set with the smallest number of stations that covers all the cities. => This takes O(2^n) to run.

Greedy Approach (Approximation Algorithm): Pick the station that covers the most cities that haven’t been covered yet. (It’s OK if the station covers some cities that have been covered already). Repeat until all the cities are covered. => This takes O(n^2) to run.

```python
cities_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])
stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final_stations = set()
while cities_needed:
    best_station = None
    cities_covered = set()
    for station, cities in stations.items():
        covered = cities_needed & cities
        if len(covered) > len(cities_covered):
            best_station = station
            cities_covered = covered
    cities_needed -= cities_covered
    final_stations.add(best_station)

print(final_stations)  # {'kone', 'kfive', 'kthree', 'ktwo'}
```

## 🔗 Further Reading

* [Greedy Algorithms](https://brilliant.org/wiki/greedy-algorithm/), brilliant.org
* [Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms/), geeksforgeeks.org 2023
* ▶️ [Greedy Algorithms Tutorial](https://www.youtube.com/watch?v=bC7o8P_Ste4), FreeCodeCamp, 2022
