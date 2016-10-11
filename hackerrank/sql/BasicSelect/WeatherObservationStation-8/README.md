link :
https://www.hackerrank.com/challenges/weather-observation-station-8

<pre>
Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and
 u) as both their first and last characters. Your result cannot contain
  duplicates.
</pre>

![_config.yml](./table.png)

<pre>
CITY 이름을 출력하는데 첫글자가 모음이면서 마지막 글자도 모음이여야 한다.
물론 중복 제거 SELECT DISTINCT CITY FROM STATION
이제부터가 문제다. 전에 하던것처럼 정규표현을 쓰면 너무 길어진다.
찾아보니 SUBSTR과 IN을 쓰면 되더라 ㅎㅎ
SUBSTR(string, base, offset) : 이름 그대로 문자열을 자른다.(base부터 base+offset까지)
첫글자는 SUBSTR(CITY,1,1)을 하면 나온다. 거기에 IN을 쓰면 첫글자가 저기에 포함되는가를 확인할
수 있다. 마찬가지로 마지막 글자 역시 base에 -1을 하면 뒤로가서 확인할 수 있다.
기억하자! SUBSTR(string, base, offset) IN ();
* 사실 대문자 소문자 둘 중 하나만 써도 된다. 하나만 써도 둘다 뽑아주는 듯 하다.
</pre>

```sql
SELECT DISTINCT CITY FROM STATION WHERE SUBSTR(CITY,1,1)
IN('A','E','I','O','U','a','e','i','o','u') and SUBSTR(CITY,-1,1)
IN('A','E','I','O','U','a','e','i','o','u');
```

