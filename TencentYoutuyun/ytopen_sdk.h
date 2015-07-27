#ifndef _YTOPEN_SDK_
#define _YTOPEN_SDK_
#include <string>
#include <vector>

class ytopen_sdk
{
    public:
        typedef struct AppSign
        {
            uint32_t app_id;
            std::string secret_id;
            std::string secret_key;
            std::string user_id;
        }AppSign;

    public:
        /**
         * @brief Init
         * @param t_app_sign 密钥身份信息
         */
        void Init(const AppSign& t_app_sign);


        /**
         * @brief DetectFace
         * @param imageData 待检测的图片数据
         * @param isBigFace 是否大脸模式
         * @param rsp 返回的检测结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int DetectFace(const std::string& imageData, bool isBigFace, std::string &rsp);


        /**
         * @brief FaceShape
         * @param imageData 待检测的图片数据
         * @param isBigFace 是否大脸模式
         * @param rsp 返回的检测结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int FaceShape(const std::string& imageData, bool isBigFace, std::string &rsp);


        /**
         * @brief FaceCompare
         * @param imageA 待比对的A图片数据
         * @param imageB 待比对的B图片数据
         * @param rsp 返回的比对结果，JSON字符串，字段参见API文档
         * @return
         */
        int FaceCompare(const std::string& imageA, const std::string&imageB, std::string &rsp);


        /**
         * @brief FaceVerify
         * @param person_id 待验证的人脸id
         * @param imageData 待验证的图片数据
         * @param rsp 返回的人脸验证匹配结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int FaceVerify(const std::string& person_id, const std::string& imageData, std::string &rsp);


        /**
         * @brief FaceIdentify
         * @param group_id 识别的组id
         * @param imageData 待识别的图片数据
         * @param rsp 返回的top5识别结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int FaceIdentify(const std::string& group_id, const std::string& imageData, std::string &rsp);


        /**
         * @brief NewPerson
         * @param person_id 新建的个体id，用户指定，需要保证app_id下的唯一性
         * @param person_name 待验证的图片数据
         * @param group_ids 新建的个体存放的组id，可以指定多个组id，用户指定（组默认创建）
         * @param imageData 包含个体人脸的图片数据
         * @param tag 备注信息，用户自解释字段
         * @param rsp 返回的新建状态结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int NewPerson(const std::string& person_id, const std::string &person_name, const std::vector<std::string> &group_ids, const std::string& imageData, const std::string &tag, std::string &rsp);


        /**
         * @brief DelPerson
         * @param person_id 待删除的个体id
         * @param rsp 返回的删除状态结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int DelPerson(const std::string& person_id, std::string &rsp);


        /**
         * @brief AddFace
         * @param person_id 新增人脸的个体身份id
         * @param imageDatas 待增加的包含人脸的图片数据，可加入多张（包体大小<2m）
         * @param tag 人脸备注信息，用户自解释字段
         * @param rsp 返回的人脸增加状态结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int AddFace(const std::string& person_id, const std::vector<std::string>& imageDatas, const std::string &tag, std::string &rsp);


        /**
         * @brief DelFace
         * @param person_id 待删除人脸的个体身份id
         * @param face_ids 待删除的人脸id
         * @param rsp 返回的人脸删除状态结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int DelFace(const std::string& person_id, const std::vector<std::string>& face_ids, std::string &rsp);


        /**
         * @brief SetInfo
         * @param person_id 待设置的个体身份id
         * @param person_name 新设置的个体名字
         * @param tag 新设置的人脸备注信息
         * @param rsp 返回的状态结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int SetInfo(const std::string& person_id, const std::string& person_name, const std::string& tag, std::string &rsp);


        /**
         * @brief GetInfo
         * @param person_id 待查询的个体身份id
         * @param rsp 返回的查询结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int GetInfo(const std::string& person_id, std::string &rsp);


        /**
         * @brief GetGroupIds
         * @param rsp 返回的组列表查询结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int GetGroupIds(std::string &rsp);


        /**
         * @brief GetPersonIds
         * @param group_id 待查询的组id
         * @param rsp 返回的个体列表查询结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int GetPersonIds(const std::string& group_id, std::string &rsp);


        /**
         * @brief GetFaceIds
         * @param person_id 待查询的个体id
         * @param rsp 返回的人脸列表查询结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int GetFaceIds(const std::string& person_id, std::string &rsp);


        /**
         * @brief GetFaceInfo
         * @param face_id 待查询的人脸id
         * @param rsp 返回的人脸信息查询结果，JSON字符串，字段参见API文档
         * @return 0成功 -1失败
         */
        int GetFaceInfo(const std::string&face_id , std::string &rsp);

    private:
        int curl_method(const std::string& addr, const std::string &req_str, std::string &rsp_str);
        
    private:
        static std::string host;
        AppSign app_sign;
        std::string app_id;
};

#endif
