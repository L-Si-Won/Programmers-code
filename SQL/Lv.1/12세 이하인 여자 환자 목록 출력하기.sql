select PT_NAME, PT_NO, GEND_CD, AGE,
    case when TLNO is NULL
        then "NONE"
        else TLNO
        end TLNO
from PATIENT
where GEND_CD like "W" and AGE <= 12
order by AGE desc, PT_NAME asc
