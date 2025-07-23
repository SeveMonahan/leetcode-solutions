WITH
    ranked_employees AS (
        SELECT
            id,
            DENSE_RANK() OVER (
                PARTITION BY departmentId
                ORDER BY salary DESC
            ) as salary_rank
        FROM
            Employee
    )
SELECT
    d.name as "Department",
    e.name as "Employee",
    e.salary as Salary
FROM
    ranked_employees
JOIN
    Employee AS e
    ON e.id = ranked_employees.id
JOIN
    Department AS d
    ON e.departmentId = d.id
    WHERE ranked_employees.salary_rank <= 3
