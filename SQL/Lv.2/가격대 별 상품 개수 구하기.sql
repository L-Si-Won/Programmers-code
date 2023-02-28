select floor(price / 10000) * 10000 PRICE_GROUP, count(*)
from PRODUCT
group by PRICE_GROUP
order by PRICE_GROUP asc
