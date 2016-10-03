link :
https://www.hackerrank.com/challenges/revising-the-select-query

<pre>
Query all columns for all American cities in CITY with populations larger than 100,000.
The CountryCode for America is USA.
</pre>

![_config.yml](./table.png)

<pre>
이 문제는 Select를 사용해 해결하는 가장 간단한 문제다.
CITY 테이블에서 인구수가 100,000보다 큰 모든 미국 도시를 가져오는데 모든 column을 다 가져오라고 한다.
모든 column은 [Select *]
인구수 100,000은 [where POPULATION > 100000]
미국 도시는 CountryCode가 USA라고 했으니까 [where COUNTRYCODE = "USA"]
이걸 다 합치면
</pre>

```sql
select * from CITY where COUNTRYCODE="USA" AND POPULATION > 100000
```

