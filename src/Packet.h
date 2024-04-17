struct Packet {
	unsigned int ip_version;
	unsigned int ip_proto;
	char *ip_src, *ip_dst;
	union {
		int checksum_status;
		unsigned short src_port, dst_port;
		struct {
			unsigned int seq;
			unsigned int flags;
		} tcp;
		struct (
		) udp;
	} highlevel;
}
