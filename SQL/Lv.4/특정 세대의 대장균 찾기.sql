SELECT A.ID
FROM ECOLI_DATA A INNER JOIN ECOLI_DATA B INNER JOIN ECOLI_DATA C
ON A.PARENT_ID = B.ID AND B.PARENT_ID = C.ID
WHERE C.PARENT_ID IS NULL
ORDER BY A.ID
