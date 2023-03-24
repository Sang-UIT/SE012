#include "Graphics.h"

Graphics::Graphics()
{
	
}

Graphics::~Graphics()
{
	
}

LPDIRECT3DDEVICE9 device = NULL;
int Graphics::Init_Direct3D(HWND hWnd, int width, int height, bool full)
{
	// Initialize Direct3D
	DirectDevice::d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (DirectDevice::d3d == NULL)
	{
		MessageBox(NULL, "Error create d3d", "Error create d3d", MB_OK);
		return 0;
	}	
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true; // Window ở dạng cửa sổ, không phải full màn hình
	d3dpp.BackBufferCount = 1; // Số lượng Back buffer
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Chọn UNKNOW, DirectX sẽ tự chọn 1 định dạng phù hợp cho Device
	d3dpp.BackBufferHeight = height; // chiều cao cảu BackBuffer
	d3dpp.BackBufferWidth = width; // Chiều dài của BackBuffer
	d3dpp.hDeviceWindow = hWnd; // Gán HandleWindow cho Device
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // Phương thức swap của Buffer
	
	// Create Direct3D device

	HRESULT result = DirectDevice::d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		// Reports Direct3D9 (ERROR) ASSERTION FAILED! on some systems
		// But there is really no error
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		// Does not work if graphics card lacks hardware vertex processing
		// D3DCREATE_HARDWARE_VERTEXPROCESSING
		&d3dpp,
		&device
	);

	if (device == NULL) {
		MessageBox(hWnd, "Error creating Direct3D device", "Error", MB_OK);
		return 0;
	}

	//Set current device
	DirectDevice::d3ddev = device;
	if (FAILED(result)) 
	{
		MessageBox(NULL,"Error creating Direct3D device","Error creating Direct3D device",MB_OK );
		return 0;
	}
	//clear the backbuffer to black
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 255, 255), 1.0f, 0);

	//create pointer to the back buffer
	device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &DirectDevice::backbuffer);

	return 1;
}

LPDIRECT3DSURFACE9 Graphics::LoadSurface(char* filename)
{
	LPDIRECT3DSURFACE9 surface = NULL;
	D3DXIMAGE_INFO info;
	HRESULT result;

	//get width and height from bitmap file
	result = D3DXGetImageInfoFromFile(filename, &info);
	if (result != D3D_OK) {
		return NULL;
	}
	//create surface
	result = DirectDevice::d3ddev->CreateOffscreenPlainSurface(
		info.Width, //width of the surface
		info.Height,
		D3DFMT_X8R8G8B8, //surface format
		D3DPOOL_DEFAULT, //memory pool to use
		&surface, //pointer to the surface
		NULL //reserved (always NULL)
	);

	if (result != D3D_OK) {
		return NULL;
	}

	//load surface from file into newly created surface
	result = D3DXLoadSurfaceFromFile(
		surface, //destination surface
		NULL, //destination palette
		NULL, //destination rectangle
		filename, //source filename
		NULL, //source rectangle
		D3DX_DEFAULT, //controls how image is filtered
		0, //transparency (0 for none)
		NULL //source image info (usually NULL)
	);

	//make sure file was loaded okay
	if (result != D3D_OK) {
		return NULL;
	}
	return surface;
}

LPDIRECT3DTEXTURE9 Graphics::LoadTexture(char* filename, D3DCOLOR transcolor)
{
	LPDIRECT3DTEXTURE9 texture = NULL;

	//the struct for reading bitmap file info
	D3DXIMAGE_INFO info;

	HRESULT result;
	//get width & height from bitmap file
	result = D3DXGetImageInfoFromFile(filename, &info);
	if (result != D3D_OK) {
		return NULL;
	}

	//create the new texture by loading bitmap image file
	D3DXCreateTextureFromFileEx(
		DirectDevice::d3ddev,//Direct3D device object
		filename,			//bitmap filename
		info.Width,			//bitmap img width
		info.Height,		//bitmap img height
		1,					//mip-map levels (1 for no chain)
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,			//color key for transparency
		&info,				//bitmap file info (from loaded file)
		NULL,				//color palette
		&texture			//destination texture
	);

	if (result != D3D_OK) {
		return NULL;
	}

	return texture;
}

