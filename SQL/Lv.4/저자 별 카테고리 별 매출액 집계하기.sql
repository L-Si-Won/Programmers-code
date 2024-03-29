WITH DATA AS (
    SELECT
        BOOK_SALES.SALES_DATE, BOOK_SALES.SALES, BOOK.*, SUM(BOOK.PRICE * BOOK_SALES.SALES) TOTAL_PRICE
    FROM
        BOOK_SALES LEFT JOIN BOOK
    ON
        BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
    WHERE
        BOOK_SALES.SALES_DATE LIKE '2022-01%'
    GROUP BY
        BOOK_SALES.BOOK_ID
),
    DATA2 AS (
        SELECT
            *, SUM(TOTAL_PRICE) TOTAL_SALES
        FROM
            DATA
        GROUP BY
            DATA.AUTHOR_ID, DATA.CATEGORY
    )

SELECT
    AUTHOR.AUTHOR_ID, AUTHOR.AUTHOR_NAME, DATA2.CATEGORY, DATA2.TOTAL_SALES
FROM
    AUTHOR INNER JOIN DATA2
ON
    AUTHOR.AUTHOR_ID = DATA2.AUTHOR_ID
ORDER BY
    AUTHOR.AUTHOR_ID ASC, DATA2.CATEGORY DESC;
