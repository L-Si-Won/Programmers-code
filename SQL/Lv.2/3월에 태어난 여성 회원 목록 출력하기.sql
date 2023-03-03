select MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d')
from MEMBER_PROFILE
where DATE_OF_BIRTH like '%-03-%' and GENDER like 'W' and TLNO is not NULL
order by MEMBER_ID asc
