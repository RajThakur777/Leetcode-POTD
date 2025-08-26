# Write your MySQL query statement below
SELECT s.student_id , s.student_name , sub.subject_name , COUNT(e.subject_name) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY student_id , student_name , subject_name
ORDER BY student_id , subject_name;