# Write your MySQL query statement below
SELECT pm.product_id, COALESCE(pr.price, 10) AS price
FROM (
    SELECT DISTINCT product_id FROM Products pn
) pm
LEFT JOIN (
    SELECT p2.product_id, p2.new_price AS price
    FROM Products p2
    JOIN (
        SELECT p1.product_id, MAX(p1.change_date) AS new_date
        FROM Products p1
        WHERE p1.change_date <= '2019-08-16'
        GROUP BY p1.product_id
    ) latest
    ON p2.product_id = latest.product_id
    AND p2.change_date = latest.new_date
) pr
ON pm.product_id = pr.product_id;




