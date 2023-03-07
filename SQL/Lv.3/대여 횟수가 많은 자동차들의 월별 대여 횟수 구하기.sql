select MONTH(START_DATE) MONTH, CAR_ID, count(*) RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where CAR_ID IN (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE >= '2022-08-01' and START_DATE <= '2022-10-31'
    group by CAR_ID
    having count(CAR_ID) >= 5
) and (START_DATE >= '2022-08-01' and START_DATE <= '2022-10-31')
group by MONTH, CAR_ID
having RECORDS > 0
order by MONTH asc, CAR_ID desc
