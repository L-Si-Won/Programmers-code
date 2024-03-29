WITH FH AS (
    SELECT *, SUM(TOTAL_ORDER) TOTAL_FH
    FROM FIRST_HALF
    GROUP BY FLAVOR
), JL AS (
    SELECT *, SUM(TOTAL_ORDER) TOTAL_JL
    FROM JULY
    GROUP BY FLAVOR
), TOTAL AS (
    SELECT FH.*, FH.TOTAL_FH + JL.TOTAL_JL TOTAL_SUM
    FROM FH INNER JOIN JL
    ON FH.FLAVOR = JL.FLAVOR
)

SELECT FLAVOR
FROM TOTAL
ORDER BY TOTAL_SUM DESC
LIMIT 3
