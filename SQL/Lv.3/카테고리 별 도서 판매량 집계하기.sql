select a.CATEGORY, sum(b.SALES) TOTAL_SALES
from BOOK a inner join BOOK_SALES b
on a.BOOK_ID = b.BOOK_ID
where TO_CHAR(b.SALES_DATE, 'YYYY-mm-dd') like '2022-01%'
group by a.CATEGORY
order by a.CATEGORY asc
