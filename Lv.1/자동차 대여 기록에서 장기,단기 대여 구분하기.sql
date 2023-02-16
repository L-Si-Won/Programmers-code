select HISTORY_ID, CAR_ID,
    DATE_FORMAT(START_DATE, "%Y-%m-%d") START_DATE,
    DATE_FORMAT(END_DATE, "%Y-%m-%d") END_DATE,
    case when DATEDIFF(END_DATE, START_DATE) >= 29
        then "장기 대여"
        else "단기 대여"
        end RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where START_DATE like '2022-09%'
order by HISTORY_ID desc
