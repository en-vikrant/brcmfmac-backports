/*
 * Copyright (c) 2011 Atheros Communications Inc.
 * Copyright (c) 2011-2012 Qualcomm Atheros, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef WMICONFIG_H
#define WMICONFIG_H

struct sk_buff *ath6kl_wmi_get_buf(u32 size);
void ath6kl_tm_rx_wmi_event(struct ath6kl *ar, void *buf, size_t buf_len);
void ath6kl_wmicfg_send_stats(struct ath6kl_vif *vif,
			      struct target_stats *stats);
void ath6kl_wmicfg_send_channel_list_reply(struct wmi *wmi, struct wmi_channel_list_reply *reply);
void ath6kl_wmicfg_send_fix_rates_reply(struct wmi *wmi, struct wmi_fix_rates_reply *reply);
#endif
