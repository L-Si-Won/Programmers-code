select substr(PRODUCT_CODE, 1, 2) CATEGORY, count(*)
from PRODUCT
group by CATEGORY
order by CATEGORY asc
