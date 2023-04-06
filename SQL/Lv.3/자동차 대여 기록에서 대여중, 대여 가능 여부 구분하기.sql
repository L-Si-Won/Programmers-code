select CAR_ID,
    case when CAR_ID IN (
        select CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where START_DATE - TO_DATE('2022-10-16', 'YYYY-MM-DD') <= 0
            and END_DATE - TO_DATE('2022-10-16', 'YYYY-MM-DD') >= 0
    )
    then '대여중'
    else '대여 가능'
    end AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by CAR_ID
order by CAR_ID desc
