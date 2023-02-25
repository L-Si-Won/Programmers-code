select i.INGREDIENT_TYPE, sum(f.TOTAL_ORDER)
from FIRST_HALF f inner join ICECREAM_INFO i
on f.FLAVOR = i.FLAVOR
group by i.INGREDIENT_TYPE
order by f.TOTAL_ORDER asc
