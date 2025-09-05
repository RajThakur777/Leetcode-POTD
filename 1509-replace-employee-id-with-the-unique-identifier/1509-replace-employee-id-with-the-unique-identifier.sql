# Write your MySQL query statement below
SELECT e2.unique_id AS unique_id , e1.name AS name
FROM Employees AS e1
LEFT JOIN EmployeeUNI AS e2
ON e1.id = e2.id;