# Write your MySQL query statement below
SELECT c.category, COALESCE(x.accounts_count, 0)  AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL 
    SELECT 'Average Salary' 
    UNION ALL
    SELECT 'High Salary'
) c
LEFT JOIN (
    SELECT t.category, COUNT(t.account_id) AS accounts_count
    FROM (
        SELECT account_id, income,
        CASE WHEN income < '20000' THEN 'Low Salary'
            WHEN income >= '20000' AND income <= '50000' THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
        FROM Accounts
    ) t
    GROUP BY t.category
) x
ON c.category = x.category
ORDER BY accounts_count DESC
;

