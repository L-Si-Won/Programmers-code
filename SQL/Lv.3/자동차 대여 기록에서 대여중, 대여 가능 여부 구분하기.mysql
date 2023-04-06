select CAR_ID,
    case when CAR_ID IN (
        select CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where DATEDIFF(START_DATE, '2022-10-16') <= 0 and DATEDIFF(END_DATE, '2022-10-16') >= 0
    )
    then '대여중'
    else '대여 가능'
    end AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by CAR_ID
order by CAR_ID desc
