link :
https://www.hackerrank.com/challenges/weather-observation-station-5

<pre>
Query the two cities in STATION with the shortest and longest CITY names, as well
 as their respective lengths (i.e.: number of characters in the name). If there is
  more than one smallest or largest city, choose the one that comes first when
   ordered alphabetically.
</pre>

![_config.yml](./table.png)

<pre>
점점 어려워진다..
도시 이름 중에 가장 짧은 이름과 긴 이름 그리고 그 이름의 글자수를 가져온다.
글자수가 같은게 있으면 알파벳 순으로 가장 앞에 있는걸 가져온다.
LENGTH는 column name의 글자수를 가져온다.
ORDER BY는 정렬을 의미하는데 LENGTH(CITY)로 했으니 CITY의 글자 수대로 오름차순 정렬한다.
LIMIT는 rx의 take 같은거다. 제한된 수만큼 가져온다.
LIMIT 1은 가장 위에 있는 하나를 가져온다.(LIMIT 2,4 하면 두번째부터 네번째까지)
DESC는 descending을 의미한다. 즉, order by가 내림차순으로 된다.
가장 긴 글자 중 알파벳 상 가장 앞에 있는 걸 가져올 수 있다.
</pre>

```sql
SELECT CITY, LENGTH(CITY) FROM STATION ORDER BY LENGTH(CITY) LIMIT 1 ;
SELECT CITY, LENGTH(CITY) FROM STATION ORDER BY LENGTH(CITY) DESC LIMIT 1
```

