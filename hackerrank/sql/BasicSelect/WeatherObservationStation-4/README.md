link :
https://www.hackerrank.com/challenges/weather-observation-station-4

<pre>
Let  be the number of CITY entries in STATION, and let  be the number of distinct
 CITY names in STATION; query the value of  from STATION. In other words, find the difference between the total number of CITY entries in the table and the number 
 of distinct CITY entries in the table.
</pre>

![_config.yml](./table.png)

<pre>
COUNT를 새로 배웠다.
STATION 테이블에서 CITY의 갯수와 중복을 제거한 CITY 갯수를 세서 그들의 차를 출력해야된다.
갯수를 셀 때는 COUNT, 최대값은 MAX 등으로 찾을 수 있다고한다.
이런애를 집계함수라고 한다고 한다. 집계함수는 Select와 from을 한 번만 사용한다.
</pre>

```sql
Select COUNT(CITY) - COUNT(DISTINCT CITY) from STATION
```

