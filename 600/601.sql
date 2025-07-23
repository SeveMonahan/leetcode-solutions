WITH
    filtered_stadium AS (
        SELECT
            id,
            visit_date,
            people,
            -- Above is equivalent to SELECT * but is written explictly
            id - ROW_NUMBER() OVER (ORDER BY id) AS grp
        FROM
            Stadium as s
        WHERE
            s.people >= 100
    ),
    sought_grps AS (
        SELECT
            grp
        FROM
            filtered_stadium
        GROUP BY
            grp
        HAVING
            COUNT(*) >= 3
    )
SELECT
    fs.id, fs.visit_date, fs.people
FROM
    filtered_stadium AS fs
JOIN
    sought_grps
    ON fs.grp = sought_grps.grp
