select DISTINCT(a.CAR_ID)
from CAR_RENTAL_COMPANY_CAR a inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY b
on a.CAR_ID = b.CAR_ID
where a.CAR_TYPE like '세단' and TO_CHAR(b.START_DATE, 'YYYY-mm-dd') like '%-10-%'
order by a.CAR_ID desc
