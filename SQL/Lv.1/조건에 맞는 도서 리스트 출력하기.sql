select BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, "%Y-%m-%d") PUBLISHED_DATE
from BOOK
where PUBLISHED_DATE like "2021%"
    and CATEGORY like "인문"
order by PUBLISHED_DATE asc
