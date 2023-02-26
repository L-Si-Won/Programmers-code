select MCDP_CD '진료과코드', count(MCDP_CD) '5월예약건수'
from APPOINTMENT
where APNT_YMD like '2022-05%'
group by MCDP_CD
order by count(*) asc, MCDP_CD asc
