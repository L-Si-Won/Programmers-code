WITH DATA AS (
    SELECT
        R.HISTORY_ID, R.CAR_ID, C.DAILY_FEE, C.CAR_TYPE, R.END_DATE - R.START_DATE + 1 DURATION, (
            CASE
            WHEN R.END_DATE - R.START_DATE + 1 >= 90 THEN '90일 이상'
            WHEN R.END_DATE - R.START_DATE + 1 >= 30 THEN '30일 이상'
            WHEN R.END_DATE - R.START_DATE + 1 >= 7 THEN '7일 이상'
            ELSE '7일 미만'
            END
        ) DURATION_TYPE
    FROM
        CAR_RENTAL_COMPANY_CAR C
        INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY R
    ON
        C.CAR_ID = R.CAR_ID
    WHERE
        C.CAR_TYPE LIKE '트럭'
)

SELECT
    DATA.HISTORY_ID, (
        ROUND(DATA.DAILY_FEE * DATA.DURATION * (100 - NVL(D.DISCOUNT_RATE, 0)) * 0.01, 0)
    ) FEE
FROM
    DATA LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN D
ON
    DATA.CAR_TYPE = D.CAR_TYPE
    AND DATA.DURATION_TYPE = D.DURATION_TYPE
ORDER BY FEE DESC, DATA.HISTORY_ID DESC;
