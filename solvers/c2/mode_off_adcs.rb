cmd("CFDP SEND_FILE with CLASS 1, DEST_ID '24', SRCFILENAME '/home/op1/c2/es_adcs_tbl_off.json', DSTFILENAME '/cf/es_adcs_tbl_off.json'")
sleep(5)
cmd("EYASSAT_IF LOAD_TBL with CCSDS_STREAMID 6613, CCSDS_SEQUENCE 49152, CCSDS_LENGTH 67, CCSDS_FUNCCODE 2, CCSDS_CHECKSUM 0, ID 0, TYPE 1, FILENAME '/cf/es_adcs_tbl_off.json'")
sleep(5)
# Need to run it twice to get the wheel to stop based on order operations
cmd("EYASSAT_IF LOAD_TBL with CCSDS_STREAMID 6613, CCSDS_SEQUENCE 49152, CCSDS_LENGTH 67, CCSDS_FUNCCODE 2, CCSDS_CHECKSUM 0, ID 0, TYPE 1, FILENAME '/cf/es_adcs_tbl_off.json'")
