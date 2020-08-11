
#include <stdio.h>
#include <nvToolsExt.h>

static nvtxDomainHandle_t nvtx_perfstubs_domain;

void ps_tool_initialize(void)
{
  printf("ps_tool_initialize\n");
  nvtx_perfstubs_domain = nvtxDomainCreateA("PS");
}

void ps_tool_finalize(void)
{
  printf("ps_tool_finalize\n");
}

void ps_tool_start_string(const char *s)
{
  printf("ps_tool_start_string '%s'\n", s);
  nvtxEventAttributes_t attr = {};
  attr.version = NVTX_VERSION;
  attr.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
  attr.messageType = NVTX_MESSAGE_TYPE_ASCII;
  attr.message.ascii = s;
  nvtxDomainRangePushEx(nvtx_perfstubs_domain, &attr);
}

void ps_tool_stop_string(const char *s)
{
  printf("ps_tool_stop_string '%s'\n", s);
  nvtxDomainRangePop(nvtx_perfstubs_domain);
}

void ps_tool_dump_data()
{
  printf("ps_tool_dump-data\n");
}
