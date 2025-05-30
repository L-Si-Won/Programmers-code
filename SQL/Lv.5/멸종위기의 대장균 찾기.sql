WITH RECURSIVE GEN_INFO AS (
    SELECT *, 1 GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL
    
    SELECT A.*, (GENERATION + 1) AS GEN
    FROM ECOLI_DATA A INNER JOIN GEN_INFO B
    ON A.PARENT_ID = B.ID
)

SELECT COUNT(A.ID) COUNT, GENERATION
FROM GEN_INFO A LEFT JOIN ECOLI_DATA B
ON A.ID = B.PARENT_ID
WHERE B.ID IS NULL
GROUP BY GENERATION
ORDER BY GENERATION
