WITH RANK_INFO AS (
    SELECT ID, PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) RATE
    FROM ECOLI_DATA
)

SELECT A.ID, (
    CASE
        WHEN B.RATE <= 0.25 THEN 'CRITICAL'
        WHEN B.RATE <= 0.5 THEN 'HIGH'
        WHEN B.RATE <= 0.75 THEN 'MEDIUM'
        ELSE 'LOW'
    END
) COLONY_NAME
FROM ECOLI_DATA A INNER JOIN RANK_INFO B
ON A.ID = B.ID
ORDER BY A.ID
