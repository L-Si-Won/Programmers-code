select a.CATEGORY, sum(b.SALES) TOTAL_SALES
from BOOK a inner join BOOK_SALES b
on a.BOOK_ID = b.BOOK_ID
where b.SALES_DATE like '2022-01%'
group by a.CATEGORY
order by a.CATEGORY asc
