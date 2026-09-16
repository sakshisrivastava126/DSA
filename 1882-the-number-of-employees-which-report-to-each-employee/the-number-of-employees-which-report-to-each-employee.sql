# Write your MySQL query statement below
SELECT e.employee_id, e.name, t.rt reports_count, ROUND(sm/t.rt) average_age
FROM Employees e
JOIN (
    SELECT employee_id, reports_to, COUNT(reports_to) AS rt, SUM(age) AS sm
    FROM Employees
    GROUP BY reports_to
) t
ON e.employee_id = t.reports_to
ORDER BY e.employee_id;