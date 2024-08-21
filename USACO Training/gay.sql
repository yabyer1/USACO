CREATE DATABASE IF NOT EXISTS Find_A_Fade;
USE Find_A_Fade;


CREATE TABLE business_owner (
    owner_id INT AUTO_INCREMENT,
    user_id INT NOT NULL,
    business_id INT NOT NULL,
    ownership_percentage DECIMAL(5, 2),
    PRIMARY KEY (owner_id),
    FOREIGN KEY (user_id) REFERENCES user(user_id) ON DELETE CASCADE,
    FOREIGN KEY (business_id) REFERENCES business(business_id) ON DELETE CASCADE
);