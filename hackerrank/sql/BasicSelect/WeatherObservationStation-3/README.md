link :
https://www.hackerrank.com/challenges/weather-observation-station-3

<pre>
Query a list of CITY names from STATION with even ID
numbers only. You may print the results in any order,
but must exclude duplicates from your answer..
</pre>

![_config.yml](./table.png)

<pre>
오 조금 어렵다기 보다는 새로운게 나왔다. 문제를 해석해보자.
쿼리를 날리는데 CITY의 이름만 가져와라 근데 ID가 짝수여야 되고,
대답에서 중복을 제거해라.
ID 짝수는 [where ID%2=0] : '=='이 아닌것에 주의!
중복을 제거해 가져오는건 되게 쉽더라. 아 이거..
[Select DISTINCT CITY]
순서는 상관없다고 하니 이렇게 하고 합치면
</pre>

```sql
Select DISTINCT CITY from STATION where ID%2=0
```

