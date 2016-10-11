link :
https://www.hackerrank.com/challenges/weather-observation-station-10

<pre>
Query the list of CITY names from STATION that do not end with vowels.
Your result cannot contain duplicates.
</pre>

![_config.yml](./table.png)

<pre>
CITY 이름을 중복없이 뽑는데 이름 가장 끝에 모음을 가지고 있으면 안된다.
8번문제랑 한가지가 다르다.
모음이면 [안 된다] : IN 앞에 NOT을 붙여주면 된다.
그리고 이름의 맨끝을 SUBSTR로 갔었는데 이번에는 RIGHT로 가보자.
</pre>

```sql
SELECT DISTINCT CITY FROM STATION WHERE RIGHT(CITY,1) NOT IN('A','E','I','O','U')
```

