#ifndef _COMFORTZONE_DECODER_H
#define _COMFORTZONE_DECODER_H

#include "comfortzone_heatpump.h"
#include "comfortzone_frame.h"

class czdec
{
	public:
	typedef struct known_register
	{
		byte reg_num[9];

		KNOWN_REGISTER_CRAFT_NAME reg_cname;
		const char *reg_name;

		void (*cmd_r)(comfortzone_heatpump *czhp, struct known_register *kr, R_CMD *p);	  // FRAME_TYPE_02_CMD_p2, R command
		void (*cmd_w)(comfortzone_heatpump *czhp, struct known_register *kr, W_CMD *p);	  // FRAME_TYPE_02_CMD_p2, W command
		void (*reply_r)(comfortzone_heatpump *czhp, struct known_register *kr, R_REPLY *p); // FRAME_TYPE_02_REPLY, r reply
		void (*reply_w)(comfortzone_heatpump *czhp, struct known_register *kr, W_REPLY *p); // FRAME_TYPE_P2_REPLY, w reply
	} KNOWN_REGISTER;

	static comfortzone_heatpump::PROCESSED_FRAME_TYPE process_frame(comfortzone_heatpump *cz_class, CZ_PACKET_HEADER *czph);
	static void dump_frame(comfortzone_heatpump *cz_class, const char *prefix);

	// command and reply decoder
	static void cmd_r_generic(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_CMD *p);
	static void cmd_w_generic_2byte(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_temp(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_temp_1byte(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_freq(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_time(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_percentage(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_extra_hot_water(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_daylight_saving(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_sanitary_priority(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_day_delay(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_fan_speed(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_language(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_digit(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);
	static void cmd_w_clr_alarm(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);

	static void reply_r_generic_2byte(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_temp(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_temp_1byte(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_freq(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_time(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_percentage(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_extra_hot_water(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_daylight_saving(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_sanitary_priority(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_day_delay(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_fan_speed(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_language(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_digit(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_clr_alarm(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_w_generic(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_REPLY *p);

	static void empty(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, W_CMD *p);

	// status decoder
	static void reply_r_status_01(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_02(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_03(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_04(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_05(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_06(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_07(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_08(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_09(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_10(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_11(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_12(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_13(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_14(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_15(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_16(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_17(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_18(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_19(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_20(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_22(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_23(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_24(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
	static void reply_r_status_25(comfortzone_heatpump *czhp, KNOWN_REGISTER *kr, R_REPLY *p);
};

#endif
