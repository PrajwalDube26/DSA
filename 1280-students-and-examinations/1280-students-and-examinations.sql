SELECT st.student_id , st.student_name , su.subject_name , 
(
    SELECT COUNT(*)
    FROM Examinations e
    WHERE e.student_id = st.student_id AND e.subject_name = su.subject_name
) AS attended_exams

FROM Students st
CROSS JOIN Subjects su
ORDER BY st.student_id,su.subject_name;