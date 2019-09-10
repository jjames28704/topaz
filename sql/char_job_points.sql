-- MySQL dump 10.13  Distrib 5.6.17, for Win64 (x86_64)
--
-- Host: localhost    Database: dspdb
-- ------------------------------------------------------
-- Server version	5.6.21-log

--
-- Table structure for table `char_job_points`
--

DROP TABLE IF EXISTS `char_job_points`;
CREATE TABLE `char_job_points` (
  `charid` int(10) unsigned NOT NULL,
  `job_pointid` smallint(10) unsigned NOT NULL,
  `rank` tinyint(2) unsigned NOT NULL,
  INDEX `char_job_points_charid_index` (`charid`),
  UNIQUE KEY `idx_char_job_points_job_pointid_charid` (`job_pointid`,`charid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- Dump completed on 2019-09-03 20:24:32
