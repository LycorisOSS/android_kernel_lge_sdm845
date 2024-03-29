/* Copyright (c) 2012-2018, 2021, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef __Q6AFE_V2_H__
#define __Q6AFE_V2_H__
#include <dsp/apr_audio-v2.h>
#include <dsp/rtac.h>
#if defined(CONFIG_SND_SOC_TFA9872)||defined(CONFIG_SND_SOC_TFA9878)
#include <ipc/apr_tal.h>
#endif

#define IN			0x000
#define OUT			0x001
#define MSM_AFE_MONO        0
#define MSM_AFE_CH_STEREO   1
#define MSM_AFE_MONO_RIGHT  1
#define MSM_AFE_MONO_LEFT   2
#define MSM_AFE_STEREO      3
#define MSM_AFE_4CHANNELS   4
#define MSM_AFE_6CHANNELS   6
#define MSM_AFE_8CHANNELS   8

#define MSM_AFE_I2S_FORMAT_LPCM		0
#define MSM_AFE_I2S_FORMAT_COMPR		1
#define MSM_AFE_I2S_FORMAT_IEC60958_LPCM	2
#define MSM_AFE_I2S_FORMAT_IEC60958_COMPR	3

#define MSM_AFE_PORT_TYPE_RX 0
#define MSM_AFE_PORT_TYPE_TX 1

#define RT_PROXY_DAI_001_RX	0xE0
#define RT_PROXY_DAI_001_TX	0xF0
#define RT_PROXY_DAI_002_RX	0xF1
#define RT_PROXY_DAI_002_TX	0xE1
#define VIRTUAL_ID_TO_PORTID(val) ((val & 0xF) | 0x2000)

#define AFE_CLK_VERSION_V1    1
#define AFE_CLK_VERSION_V2    2
#define AFE_API_VERSION_SUPPORT_SPV3	2

#if defined(CONFIG_SND_SOC_TFA9872)||defined(CONFIG_SND_SOC_TFA9878)
/*Module ID*/
#define AFE_MODULE_ID_TFADSP          0x1000B910

/*Param ID*/
#define AFE_PARAM_ID_TFADSP_SEND_MSG  0x1000B921
#define AFE_PARAM_ID_TFADSP_READ_MSG  0x1000B922
#define AFE_PARAM_ID_TFADSP_RESP_MSG  0x1000B922

#define AFE_OPCODE_TFADSP_STATUS      0x00010B01
#define AFE_EVENT_TFADSP_STATE_INIT   0x1
#define AFE_EVENT_TFADSP_STATE_CLOSE  0x2
#define AFE_EVENT_TFADSP_STATE_CONFIGURED 0x3
#define AFE_EVENT_TFADSP_RX_MODULE_DISABLED 0x4
#define AFE_EVENT_TFADSP_TX_MODULE_DISABLED 0x5

#define AFE_RX_MODULE_ID_TFADSP 0x1000B900
#define AFE_TX_MODULE_ID_TFADSP 0x1000B901
#define AFE_RX_NONE_TOPOLOGY 0x000112fc

#if defined(AFE_TFADSP_SHARED_MEM_IPC)
/*APR packet max size: 4KB*/
#define AFE_APR_MAX_PKT_SIZE  4096
#else
// in case of CONFIG_MSM_QDSP6_APRV2_GLINK/APRV3_GLINK, with smaller APR_MAX_BUF (512)
#define AFE_APR_MAX_PKT_SIZE  APR_MAX_BUF
#endif
#endif // CONFIG_SND_SOC_TFA9872

typedef int (*routing_cb)(int port);

enum {
	/* IDX 0->4 */
	IDX_PRIMARY_I2S_RX,
	IDX_PRIMARY_I2S_TX,
	IDX_AFE_PORT_ID_PRIMARY_PCM_RX,
	IDX_AFE_PORT_ID_PRIMARY_PCM_TX,
	IDX_SECONDARY_I2S_RX,
	/* IDX 5->9 */
	IDX_SECONDARY_I2S_TX,
	IDX_MI2S_RX,
	IDX_MI2S_TX,
	IDX_HDMI_RX,
	IDX_RSVD_2,
	/* IDX 10->14 */
	IDX_RSVD_3,
	IDX_DIGI_MIC_TX,
	IDX_VOICE_RECORD_RX,
	IDX_VOICE_RECORD_TX,
	IDX_VOICE_PLAYBACK_TX,
	/* IDX 15->19 */
	IDX_SLIMBUS_0_RX,
	IDX_SLIMBUS_0_TX,
	IDX_SLIMBUS_1_RX,
	IDX_SLIMBUS_1_TX,
	IDX_SLIMBUS_2_RX,
	/* IDX 20->24 */
	IDX_SLIMBUS_2_TX,
	IDX_SLIMBUS_3_RX,
	IDX_SLIMBUS_3_TX,
	IDX_SLIMBUS_4_RX,
	IDX_SLIMBUS_4_TX,
	/* IDX 25->29 */
	IDX_SLIMBUS_5_RX,
	IDX_SLIMBUS_5_TX,
	IDX_INT_BT_SCO_RX,
	IDX_INT_BT_SCO_TX,
	IDX_INT_BT_A2DP_RX,
	/* IDX 30->34 */
	IDX_INT_FM_RX,
	IDX_INT_FM_TX,
	IDX_RT_PROXY_PORT_001_RX,
	IDX_RT_PROXY_PORT_001_TX,
	IDX_AFE_PORT_ID_QUATERNARY_MI2S_RX,
	/* IDX 35->39 */
	IDX_AFE_PORT_ID_QUATERNARY_MI2S_TX,
	IDX_AFE_PORT_ID_SECONDARY_MI2S_RX,
	IDX_AFE_PORT_ID_SECONDARY_MI2S_TX,
	IDX_AFE_PORT_ID_TERTIARY_MI2S_RX,
	IDX_AFE_PORT_ID_TERTIARY_MI2S_TX,
	/* IDX 40->44 */
	IDX_AFE_PORT_ID_PRIMARY_MI2S_RX,
	IDX_AFE_PORT_ID_PRIMARY_MI2S_TX,
	IDX_AFE_PORT_ID_SECONDARY_PCM_RX,
	IDX_AFE_PORT_ID_SECONDARY_PCM_TX,
	IDX_VOICE2_PLAYBACK_TX,
	/* IDX 45->49 */
	IDX_SLIMBUS_6_RX,
	IDX_SLIMBUS_6_TX,
	IDX_SPDIF_RX,
	IDX_GLOBAL_CFG,
	IDX_AUDIO_PORT_ID_I2S_RX,
	/* IDX 50->53 */
	IDX_AFE_PORT_ID_SECONDARY_MI2S_RX_SD1,
	IDX_AFE_PORT_ID_QUINARY_MI2S_RX,
	IDX_AFE_PORT_ID_QUINARY_MI2S_TX,
	IDX_AFE_PORT_ID_SENARY_MI2S_TX,
	/* IDX 54->117 */
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_0,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_0,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_1,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_1,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_2,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_2,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_3,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_3,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_4,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_4,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_5,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_5,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_6,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_6,
	IDX_AFE_PORT_ID_PRIMARY_TDM_RX_7,
	IDX_AFE_PORT_ID_PRIMARY_TDM_TX_7,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_0,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_0,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_1,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_1,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_2,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_2,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_3,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_3,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_4,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_4,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_5,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_5,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_6,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_6,
	IDX_AFE_PORT_ID_SECONDARY_TDM_RX_7,
	IDX_AFE_PORT_ID_SECONDARY_TDM_TX_7,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_0,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_0,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_1,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_1,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_2,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_2,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_3,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_3,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_4,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_4,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_5,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_5,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_6,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_6,
	IDX_AFE_PORT_ID_TERTIARY_TDM_RX_7,
	IDX_AFE_PORT_ID_TERTIARY_TDM_TX_7,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_0,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_0,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_1,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_1,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_2,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_2,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_3,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_3,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_4,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_4,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_5,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_5,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_6,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_6,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_7,
	IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_7,
	/* IDX 118->121 */
	IDX_SLIMBUS_7_RX,
	IDX_SLIMBUS_7_TX,
	IDX_SLIMBUS_8_RX,
	IDX_SLIMBUS_8_TX,
	/* IDX 122-> 123 */
	IDX_AFE_PORT_ID_USB_RX,
	IDX_AFE_PORT_ID_USB_TX,
	/* IDX 124 */
	IDX_DISPLAY_PORT_RX,
	/* IDX 125-> 128 */
	IDX_AFE_PORT_ID_TERTIARY_PCM_RX,
	IDX_AFE_PORT_ID_TERTIARY_PCM_TX,
	IDX_AFE_PORT_ID_QUATERNARY_PCM_RX,
	IDX_AFE_PORT_ID_QUATERNARY_PCM_TX,
	/* IDX 129-> 142 */
	IDX_AFE_PORT_ID_INT0_MI2S_RX,
	IDX_AFE_PORT_ID_INT0_MI2S_TX,
	IDX_AFE_PORT_ID_INT1_MI2S_RX,
	IDX_AFE_PORT_ID_INT1_MI2S_TX,
	IDX_AFE_PORT_ID_INT2_MI2S_RX,
	IDX_AFE_PORT_ID_INT2_MI2S_TX,
	IDX_AFE_PORT_ID_INT3_MI2S_RX,
	IDX_AFE_PORT_ID_INT3_MI2S_TX,
	IDX_AFE_PORT_ID_INT4_MI2S_RX,
	IDX_AFE_PORT_ID_INT4_MI2S_TX,
	IDX_AFE_PORT_ID_INT5_MI2S_RX,
	IDX_AFE_PORT_ID_INT5_MI2S_TX,
	IDX_AFE_PORT_ID_INT6_MI2S_RX,
	IDX_AFE_PORT_ID_INT6_MI2S_TX,
	/* IDX 143-> 160 */
	IDX_AFE_PORT_ID_QUINARY_PCM_RX,
	IDX_AFE_PORT_ID_QUINARY_PCM_TX,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_0,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_0,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_1,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_1,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_2,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_2,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_3,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_3,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_4,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_4,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_5,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_5,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_6,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_6,
	IDX_AFE_PORT_ID_QUINARY_TDM_RX_7,
	IDX_AFE_PORT_ID_QUINARY_TDM_TX_7,
	/* IDX 161 -> 162 */
	IDX_RT_PROXY_PORT_002_RX,
	IDX_RT_PROXY_PORT_002_TX,
	AFE_MAX_PORTS
};

enum afe_mad_type {
	MAD_HW_NONE = 0x00,
	MAD_HW_AUDIO = 0x01,
	MAD_HW_BEACON = 0x02,
	MAD_HW_ULTRASOUND = 0x04,
	MAD_SW_AUDIO = 0x05,
};

enum afe_cal_mode {
	AFE_CAL_MODE_DEFAULT = 0x00,
	AFE_CAL_MODE_NONE,
};

struct afe_audio_buffer {
	dma_addr_t phys;
	void       *data;
	uint32_t   used;
	uint32_t   size;/* size of buffer */
	uint32_t   actual_size; /* actual number of bytes read by DSP */
	struct      ion_handle *handle;
	struct      ion_client *client;
};

struct afe_audio_port_data {
	struct afe_audio_buffer *buf;
	uint32_t	    max_buf_cnt;
	uint32_t	    dsp_buf;
	uint32_t	    cpu_buf;
	struct list_head    mem_map_handle;
	uint32_t	    tmp_hdl;
	/* read or write locks */
	struct mutex	    lock;
	spinlock_t	    dsp_lock;
};

struct afe_audio_client {
	atomic_t	       cmd_state;
	/* Relative or absolute TS */
	uint32_t	       time_flag;
	void		       *priv;
	uint64_t	       time_stamp;
	struct mutex	       cmd_lock;
	/* idx:1 out port, 0: in port*/
	struct afe_audio_port_data port[2];
	wait_queue_head_t      cmd_wait;
	uint32_t               mem_map_handle;
};

struct aanc_data {
	bool aanc_active;
	uint16_t aanc_rx_port;
	uint16_t aanc_tx_port;
	uint32_t aanc_rx_port_sample_rate;
	uint32_t aanc_tx_port_sample_rate;
};

#if defined(CONFIG_SND_SOC_TFA9872)||defined(CONFIG_SND_SOC_TFA9878)
/*afe tfadsp msg type*/
#define AFE_TFADSP_MSG_TYPE_NORMAL 0
#define AFE_TFADSP_MSG_TYPE_RAW    1

#if defined(AFE_TFADSP_SHARED_MEM_IPC)
/*afe tfa dsp send message*/
struct afe_tfa_dsp_send_msg_t {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 set_param;
} __packed;
#else /* AFE_TFADSP_SHARED_MEM_IPC */
/*afe tfa payload*/
struct afe_tfa_dsp_payload_t {
	union {
		uint32_t num_msgs;
		char address[1];
	};
	uint32_t buf_size;
	union {
		char *buf_p;
		char buf[1];
	};
} __packed;

/*afe tfa dsp send message*/
struct afe_tfa_dsp_send_msg_t {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 set_param;
	struct afe_port_param_data_v2 pdata;
	struct afe_tfa_dsp_payload_t payload;
} __packed;
#endif /* AFE_TFADSP_SHARED_MEM_IPC */

/*afe tfa dsp read message*/
struct afe_tfa_dsp_read_msg_t {
	struct apr_hdr hdr;
	struct afe_port_cmd_get_param_v2 get_param;
} __packed;
#endif /* CONFIG_SND_SOC_TFA9872 || CONFIG_SND_SOC_TFA9878 */

#if defined(CONFIG_SND_SOC_TFA9872)
typedef int (*tfa_event_handler_t)(int devidx, int tfadsp_event);
typedef int (*dsp_send_message_t)(int devidx, int length,
	char *buf, int msg_type, int num_msgs);
typedef int (*dsp_read_message_t)(int devidx, int length, char *buf);
#endif

#if defined(CONFIG_SND_SOC_TFA9878)
int afe_tfadsp_read(void * dev, int buf_size, unsigned char *buf);
int afe_tfadsp_write(void * dev, int buf_size, const char *buf);
#endif

int afe_open(u16 port_id, union afe_port_config *afe_config, int rate);
int afe_close(int port_id);
int afe_loopback(u16 enable, u16 rx_port, u16 tx_port);
int afe_sidetone_enable(u16 tx_port_id, u16 rx_port_id, bool enable);
int afe_loopback_gain(u16 port_id, u16 volume);
int afe_validate_port(u16 port_id);
int afe_get_port_index(u16 port_id);
int afe_get_topology(int port_id);
int afe_start_pseudo_port(u16 port_id);
int afe_stop_pseudo_port(u16 port_id);
uint32_t afe_req_mmap_handle(struct afe_audio_client *ac);
int afe_memory_map(phys_addr_t dma_addr_p, u32 dma_buf_sz,
		struct afe_audio_client *ac);
int afe_cmd_memory_map(phys_addr_t dma_addr_p, u32 dma_buf_sz);
int afe_cmd_memory_map_nowait(int port_id, phys_addr_t dma_addr_p,
			u32 dma_buf_sz);
int afe_cmd_memory_unmap(u32 dma_addr_p);
int afe_cmd_memory_unmap_nowait(u32 dma_addr_p);
void afe_set_dtmf_gen_rx_portid(u16 rx_port_id, int set);
int afe_dtmf_generate_rx(int64_t duration_in_ms,
			 uint16_t high_freq,
			 uint16_t low_freq, uint16_t gain);
int afe_register_get_events(u16 port_id,
		void (*cb)(uint32_t opcode,
		uint32_t token, uint32_t *payload, void *priv),
		void *private_data);
int afe_unregister_get_events(u16 port_id);
int afe_rt_proxy_port_write(phys_addr_t buf_addr_p,
			u32 mem_map_handle, int bytes);
int afe_rt_proxy_port_read(phys_addr_t buf_addr_p,
			u32 mem_map_handle, int bytes);
void afe_set_cal_mode(u16 port_id, enum afe_cal_mode afe_cal_mode);
int afe_port_start(u16 port_id, union afe_port_config *afe_config,
	u32 rate);
int afe_set_tws_channel_mode(u16 port_id, u32 channel_mode);
int afe_port_start_v2(u16 port_id, union afe_port_config *afe_config,
		      u32 rate, u16 afe_in_channels, u16 afe_in_bit_width,
		      struct afe_enc_config *enc_config,
		      struct afe_dec_config *dec_config);
int afe_spk_prot_feed_back_cfg(int src_port, int dst_port,
	int l_ch, int r_ch, u32 enable);
int afe_spk_prot_get_calib_data(struct afe_spkr_prot_get_vi_calib *calib);
int afe_port_stop_nowait(int port_id);
int afe_apply_gain(u16 port_id, u16 gain);
int afe_q6_interface_prepare(void);
int afe_get_port_type(u16 port_id);
int q6afe_audio_client_buf_alloc_contiguous(unsigned int dir,
			struct afe_audio_client *ac,
			unsigned int bufsz,
			unsigned int bufcnt);
struct afe_audio_client *q6afe_audio_client_alloc(void *priv);
int q6afe_audio_client_buf_free_contiguous(unsigned int dir,
			struct afe_audio_client *ac);
void q6afe_audio_client_free(struct afe_audio_client *ac);
/* if port_id is virtual, convert to physical..
 * if port_id is already physical, return physical
 */
int afe_convert_virtual_to_portid(u16 port_id);

int afe_pseudo_port_start_nowait(u16 port_id);
int afe_pseudo_port_stop_nowait(u16 port_id);
int afe_set_lpass_clock(u16 port_id, struct afe_clk_cfg *cfg);
int afe_set_lpass_clock_v2(u16 port_id, struct afe_clk_set *cfg);
int afe_set_lpass_clk_cfg(int index, struct afe_clk_set *cfg);
int afe_set_digital_codec_core_clock(u16 port_id,
			struct afe_digital_clk_cfg *cfg);
int afe_set_lpass_internal_digital_codec_clock(u16 port_id,
				struct afe_digital_clk_cfg *cfg);
int afe_enable_lpass_core_shared_clock(u16 port_id, u32 enable);

int q6afe_check_osr_clk_freq(u32 freq);

int afe_send_spdif_clk_cfg(struct afe_param_id_spdif_clk_cfg *cfg,
		u16 port_id);
int afe_send_spdif_ch_status_cfg(struct afe_param_id_spdif_ch_status_cfg
		*ch_status_cfg,	u16 port_id);

int afe_spdif_port_start(u16 port_id, struct afe_spdif_port_config *spdif_port,
		u32 rate);

int afe_turn_onoff_hw_mad(u16 mad_type, u16 mad_enable);
int afe_port_set_mad_type(u16 port_id, enum afe_mad_type mad_type);
enum afe_mad_type afe_port_get_mad_type(u16 port_id);
int afe_set_config(enum afe_config_type config_type, void *config_data,
		   int arg);
void afe_clear_config(enum afe_config_type config);
bool afe_has_config(enum afe_config_type config);

void afe_set_aanc_info(struct aanc_data *aanc_info);
int afe_port_group_set_param(u16 group_id,
	union afe_port_group_config *afe_group_config);
int afe_port_group_enable(u16 group_id,
	union afe_port_group_config *afe_group_config, u16 enable);
int afe_unmap_rtac_block(uint32_t *mem_map_handle);
int afe_map_rtac_block(struct rtac_cal_block_data *cal_block);
int afe_send_slot_mapping_cfg(
	struct afe_param_id_slot_mapping_cfg *slot_mapping_cfg,
	u16 port_id);
int afe_send_custom_tdm_header_cfg(
	struct afe_param_id_custom_tdm_header_cfg *custom_tdm_header_cfg,
	u16 port_id);
int afe_tdm_port_start(u16 port_id, struct afe_tdm_port_config *tdm_port,
		       u32 rate, u16 num_groups);
void afe_set_routing_callback(routing_cb cb);
int afe_get_av_dev_drift(struct afe_param_id_dev_timing_stats *timing_stats,
		u16 port);
#if defined(CONFIG_SND_SOC_TFA9872)
int tfa_ext_register(dsp_send_message_t tfa_send_message,
		dsp_read_message_t tfa_read_message,
		tfa_event_handler_t *tfa_event_handler);
#endif
#endif /* __Q6AFE_V2_H__ */
