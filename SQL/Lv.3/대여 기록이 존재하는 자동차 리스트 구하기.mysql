select DISTINCT(a.CAR_ID)
from CAR_RENTAL_COMPANY_CAR a inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY b
on a.CAR_ID = b.CAR_ID
where a.CAR_TYPE like '세단' and b.START_DATE like '%-10-%'
order by a.CAR_ID desc

 -----------------------------------------------
 
select a.CAR_ID
from CAR_RENTAL_COMPANY_CAR a inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY b
on a.CAR_ID = b.CAR_ID
where a.CAR_TYPE like '세단' and b.START_DATE like '%-10-%'
group by a.CAR_ID
order by a.CAR_ID desc
