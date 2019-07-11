// LoadModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <string>
#include <vector>

//#include "../pipi.h"

float* ModelVerts;	//	模型的顶点数组
int sizeOfModelVerts; //	模型的顶点数组的大小
int bitSizeOfModelVerts;	//	模型的顶点数组的字节大小

bool mark = false;

void loadModel();
void load_Model();
int* mergeArray(int *inputArr_1, int sizeOfInputArr_1, int *inputArr_2, int sizeOfInputArr_2);

std::vector<float> ve;

int main()
{
	float arrHeight[] = { 1.68,1.72,1.83,2.05,2.35,1.78,2.1,1.96 };

	std::cout << sizeof(arrHeight) << std::endl;

	load_Model();
	//loadModel();
	//load_Model();

	bitSizeOfModelVerts = sizeOfModelVerts * sizeof(float);
	ModelVerts = new float[bitSizeOfModelVerts];
	if (!ve.empty()){
		memcpy(ModelVerts, &ve[0], ve.size() * sizeof(float));

	}

	for (int i = 0; i < sizeOfModelVerts; i++)
	{
		std::cout << ModelVerts[i] << std::endl;
	}
	std::cout << std::endl;
	/*
	//	数组合并测试
	int a[] = { 2,4,6,5 };
	int b[] = { 57,9,10,3,6 };


	int *aaa = mergeArray(a, sizeof(a), b, sizeof(b));

	for (int i = 0; i < 9; i++)
		printf("%d ", aaa[i]);

	*/
	//for (int i = 0; i < ve.size(); i++) {
	//	std::cout << ve[i];
	//	std::cout << "   ";
	//	/*if (i%21 == 0)
	//	{
	//		std::cout <<  std::endl;
	//	}*/
	//}

	//std::cout << ve.size();

    std::cout << "Hello World!\n"; 
}

/*
void loadModel() {
	mark = false;

	std::string strArr[] = { "../Models/teapot.obj", "../Models/cube.obj", "../Models/plane-z.obj" };

	//mark = false;

	FILE* fp;
	fopen_s(&fp, "../pipi.h", "w");

	fprintf(fp, "constexpr float levelModelVerts[] = {\n");

	Assimp::Importer importer;
	importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT);
	importer.SetPropertyInteger(AI_CONFIG_PP_PTV_NORMALIZE, true);

	unsigned flags = aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals;
//	std::cout << "######################" << arrSize << std::endl;

	for (int i = 0; i < sizeof(strArr) / sizeof(std::string); i++)
	{

		const aiScene* scene = importer.ReadFile(strArr[i], flags);
		std::cout << strArr[i] << std::endl;
		if (!scene) {
			printf("model load error.\n");
			system("pause");
			return;
		}
		const aiMesh* mesh = scene->mMeshes[0];

		uint32_t numFaces = 0;
		std::unique_ptr<uint32_t[]> vertsIndex(new uint32_t[3 * mesh->mNumFaces]);

		numFaces = mesh->mNumFaces;
		for (unsigned i = 0; i < mesh->mNumFaces; i++) {
			vertsIndex[3 * i] = mesh->mFaces[i].mIndices[0];
			vertsIndex[3 * i + 1] = mesh->mFaces[i].mIndices[1];
			vertsIndex[3 * i + 2] = mesh->mFaces[i].mIndices[2];
		}

		float *a;
		int s = mesh->mNumVertices * 7;
		std::cout << "~~~~~~~~~~" << mesh->mNumVertices << " " << std::endl;

		a = new float[s];

		for (unsigned i = 0; i < mesh->mNumVertices; i++) {
			aiVector3D tmp = mesh->mVertices[vertsIndex[i]];

			a[7 * i] = 10.0f - tmp.x;
			a[7 * i + 1] = tmp.y;
			a[7 * i + 2] = 5.0f - tmp.z;
			a[7 * i + 3] = 4.0f;
			a[7 * i + 4] = 0.0f;
			a[7 * i + 5] = 1.0f;
			a[7 * i + 6] = 0.0f;

			fprintf(fp, "%ff,%ff,%ff,", 10.0f - tmp.x, tmp.y, 5.0f - tmp.z);


			fprintf(fp, "%.0f.f,%ff,%ff,%ff,  ", 4.0, 0.0f, 1.0f, 0.0f);
			if ((i + 1) % 3 == 0)
				fprintf(fp, "\n");
		}

		fprintf(fp, "\n\n");

	}


	fprintf(fp, "};\n\n");

	//fprintf(fp, "constexpr float collisionSpheres[] = { 1.f , 1.732050f, 0.000000f, 1.00000f, -10.00000f };");
	fclose(fp);

	mark = true;

}
*/

void load_Model() {

	std::string strArr[] = {
		"../Models/cube.obj",
		"../Models/teapot.obj",
		//"../Models/knot.obj"
	};


	FILE* fp;
	fopen_s(&fp, "../pipi.h", "w");

	fprintf(fp, "constexpr float levelModelVerts[] = {\n");

	Assimp::Importer importer;
	importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT);
	importer.SetPropertyInteger(AI_CONFIG_PP_PTV_NORMALIZE, true);

	unsigned flags = aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals;

	for (int i = 0; i < sizeof(strArr) / sizeof(std::string); i++) {

		const aiScene* scene = importer.ReadFile(strArr[i], flags);
		std::cout << strArr[i] << std::endl;
		if (!scene) {
			printf("model load error.\n");
			system("pause");
			return;
		}
		const aiMesh* mesh = scene->mMeshes[0];

		uint32_t numFaces = 0;
		std::unique_ptr<uint32_t[]> vertsIndex(new uint32_t[3 * mesh->mNumFaces]);

		numFaces = mesh->mNumFaces;
		for (unsigned i = 0; i < mesh->mNumFaces; i++) {
			vertsIndex[3 * i] = mesh->mFaces[i].mIndices[0];
			vertsIndex[3 * i + 1] = mesh->mFaces[i].mIndices[1];
			vertsIndex[3 * i + 2] = mesh->mFaces[i].mIndices[2];
		}

		std::cout << "~~~~~~~~~~" << mesh->mNumVertices << " " << std::endl;
		sizeOfModelVerts += mesh->mNumVertices * 7;
		
		for (unsigned i = 0; i < mesh->mNumVertices; i++) {
			aiVector3D tmp = mesh->mVertices[vertsIndex[i]];
			ve.push_back(10.0f - tmp.x);
			ve.push_back(tmp.y);
			ve.push_back(5.0f - tmp.z);
			ve.push_back(4.0f);
			ve.push_back(0.0f);
			ve.push_back(1.0f);
			ve.push_back(0.0f);

			fprintf(fp, "%ff, %ff, %ff, ", 10.0f - tmp.x, tmp.y, 5.0f - tmp.z);

			fprintf(fp, "%.0f.f, %ff, %ff, %ff,   ", 4.0, 0.0f, 1.0f, 0.0f);
			if ((i + 1) % 3 == 0)
				fprintf(fp, "\n");
		}

		fprintf(fp, "\n\n");
	}

	fprintf(fp, "};\n\n");

	//fprintf(fp, "constexpr float collisionSpheres[] = { 1.f , 1.732050f, 0.000000f, 1.00000f, -10.00000f };");
	fclose(fp);

}

int* mergeArray(int *inputArr_1, int sizeOfInputArr_1, int *inputArr_2, int sizeOfInputArr_2){

	//int inputArr_1[4] = { 2,4,6,5 };
	//int inputArr_2[5] = { 57,9,10,3,6}; //开5个单元，只给了4个初始值，未给的是0或不定。
	//
	int numOfOutputArr = (sizeOfInputArr_1 + sizeOfInputArr_2) / sizeof(int);
	std::cout << numOfOutputArr << std::endl;

	int n;

	int *outputArr;
	outputArr = new int[numOfOutputArr];

	//	元素个数
	std::cout << sizeOfInputArr_1/sizeof(int) << std::endl;

	//	输入数组的大小
	n = sizeOfInputArr_1;
	// 将输入数组复制到输出数组中
	memcpy(outputArr, inputArr_1, n);
	//	输入数组的元素个数
	n = n / sizeof(int);
	
	//for (i = 0; i < n; i++) 
	//	printf("%d ", outputArr[i]);
	//
	//printf("\n");
	
	memcpy(outputArr + n, inputArr_2, sizeOfInputArr_2);
	/*for (int i = 0; i < 9; i++) 
		printf("%d ", outputArr[i]);
	printf("\n");*/
	return outputArr;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
