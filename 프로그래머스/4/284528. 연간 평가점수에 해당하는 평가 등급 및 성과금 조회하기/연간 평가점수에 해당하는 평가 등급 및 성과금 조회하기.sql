-- 코드를 작성해주세요
WITH EMP_GRADE AS (
    SELECT
        EMP_NO,
        CASE
            WHEN AVG(SCORE) >= 96 THEN 'S'
            WHEN AVG(SCORE) >= 90 THEN 'A'
            WHEN AVG(SCORE) >= 80 THEN 'B'
            ELSE 'C'
        END AS GRADE
    FROM HR_GRADE
    GROUP BY EMP_NO
),
BONUS_RATE AS (
    SELECT 'S' AS GRADE, 0.2 AS RATE
    UNION
    SELECT 'A', 0.15
    UNION
    SELECT 'B', 0.1
    UNION
    SELECT 'C', 0
)

SELECT 
    e.EMP_NO,
    e.EMP_NAME,
    g.GRADE,
    e.SAL * r.RATE AS BONUS
FROM HR_EMPLOYEES e
JOIN EMP_GRADE g
    ON e.EMP_NO = g.EMP_NO
JOIN BONUS_RATE r
    ON g.GRADE = r.GRADE
ORDER BY EMP_NO;
