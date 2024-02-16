CRT_OUT := $(OUT_DIR)/crt

CRTI_OBJ := $(CRT_OUT)/crti.s.o
CRTN_OBJ := $(CRT_OUT)/crtn.s.o

CRTBEGIN_OBJ := $(CRT_OUT)/crtbegin.o
CRTEND_OBJ := $(CRT_OUT)/crtend.o

crt: crt_dir $(CRTI_OBJ) $(CRTBEGIN_OBJ) $(CRTEND_OBJ) $(CRTN_OBJ)

.SECONDEXPANSION:
$(CRTI_OBJ) $(CRTN_OBJ): %.s.o: $(ARCH_DIR)/x86/crt/$$(notdir %).s
	@$(CC) $(CFLAGS) -c $< -o $@

$(CRTBEGIN_OBJ) $(CRTEND_OBJ):
	@OBJ=`$(CC) $(CFLAGS) -print-file-name=$(notdir $@)` && cp $$OBJ $@

crt_dir:
	@mkdir -pv $(CRT_OUT)
